
export interface Arista{ //Inteface el equivalente al struct 
                         //Aparentemente sin constructor
                         //No son clases, es como el type en todo sentido [etiquetas]
    destino: string;
    peso: number;
}

export class MyGraph {

    private readonly esUnidireccional : boolean;
    private readonly listAdyacencia: Map<string, Arista[]> = new Map(); // ts Map === c++ unordered_map

    constructor(esUnidireccional: boolean = false){
        this.esUnidireccional = esUnidireccional;
    }

    agregarVertice(nodo: string): void{

        if(!this.listAdyacencia.has(nodo)){ //has devuelve un bool
            this.listAdyacencia.set(nodo, []); //ts set mas o menos igual a c++ [] = valor (puede sobreescribir el valor)
        }
 
    }

    agregarArista( origen : string, destino:string, peso:number): void{

        if(!Number.isFinite(peso)){
            throw new Error(`En dijkstra se requieren pesos finitos: ${peso}`);
        }

        if(peso < 0){
            throw new Error(`En dijkstra no se meten pesos negativos: ${peso}`);
        }

        this.agregarVertice(origen);
        this.agregarVertice(destino);

        this.listAdyacencia.get(origen)!.push({destino, peso}) //Es un shortcut de sintaxis, si  el nombre de la variable
                                                               //coincide con el nombre del atributo se puede escribir nada mas una vez
                                                               // tambien ubiera funcionado {destino:destino, peso:peso} {Es un vector de aristas(vecinos)}

        if(!this.esUnidireccional){
            this.listAdyacencia.get(destino)!.push({destino: origen, peso})
        }
    }

    tieneVertice(nodo:string): boolean {

        return this.listAdyacencia.has(nodo);

    }

    getVecinos(nodo:string): Arista[]{

        const vecinos = this.listAdyacencia.get(nodo); //A diferencia del c++ no ocupo iterador q padre 

        if(!vecinos){
            throw new Error(`No existe el nodo: ${nodo}`)
        }

        return vecinos;
    }
 
    // IterableIterator = Generador paso a paso (Iterator) que además se puede recorrer con for...of (Iterable).
    // Entrega los noodos/vertices uno a uno bajo demanda en vez de cargar todos juntos en memoria como un Array.
    
    getVertices() : IterableIterator<string>{ //
        return this.listAdyacencia.keys();
    }

}