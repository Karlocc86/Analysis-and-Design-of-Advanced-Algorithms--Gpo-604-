import { MyGraph } from "./MyGraph";
import { MinPriorityQueue } from "./minPriorityQueue";

export class ResultadoDijkstra{

    public readonly distancias: ReadonlyMap<string, number>;
    public readonly migajasDePan: ReadonlyMap<string,string>;
    
    constructor(distancias: ReadonlyMap<string,number>, migajasDePan: ReadonlyMap<string,string>){
        this.distancias = distancias;
        this.migajasDePan = migajasDePan;
    }
   
    trayecto(destino:string): string[]{

        const dist = this.distancias.get(destino);
        if(dist === undefined || dist === Infinity){
            return [];
        }

        const camino : string[] = [];
        
        //(Union type) Puede contener un string o un undefined. Se usa debido a que al consultar .get(destino)
        // un Map devuelve (Valor | undefined), sin esto el compilador marca error de tipo.

        let actual:string | undefined = destino;

        while(actual && this.migajasDePan.has(actual)){
            camino.push(actual);
            actual = this.migajasDePan.get(actual);
        }
        if(actual){
            camino.push(actual);
        }

        return camino.reverse();

        
    }
}   


export class Dijkstra{

    private constructor() {} //Simulamos un explicit no, clase utilitaria
                            //no necesita ser instanciada/creada

    //static es para indicar que el metodo le pertenece a la clase 
    public static resolver(grafo: MyGraph, origen: string): ResultadoDijkstra{

        if(!grafo.tieneVertice(origen)){
            throw new Error(`El nodo origen: ${origen} no existe`);
        }

        const distancias = new Map<string,number>();
        const migajasDePan = new Map<string,string>();

        for(const v of grafo.getVertices()){
            distancias.set(v,Infinity);
        }

        distancias.set(origen,0);

        const pq = new MinPriorityQueue<string>();

        pq.push(0, origen);

        while(!pq.isEmpty){

            const elemento = pq.pop();
            if(!elemento) break;

            const [distanciaActual, u] = elemento;

            if(distanciaActual > (distancias.get(u) ?? Infinity)){
                continue;
            }

            for(const arista of grafo.getVecinos(u)){
                const v = arista.destino;
                const peso = arista.peso;
                const nuevaDistancia = distanciaActual + peso;

                if( nuevaDistancia < (distancias.get(v) ?? Infinity)){
                    distancias.set(v, nuevaDistancia);
                    migajasDePan.set(v,u);
                    pq.push(nuevaDistancia,v);
                }
            }

          
        }

          return new ResultadoDijkstra(distancias, migajasDePan);
    }



}

