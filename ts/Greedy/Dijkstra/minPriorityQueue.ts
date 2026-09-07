//Lastimosamente en ts no existe una min pqueue
//asi que toco implementarla

export type NodoHeap<T> = [prioridad:number, elemento: T];

export class MinPriorityQueue<T>{


    private heap: NodoHeap<T>[] = []; //El arbol heap que es un arreglo -> Siendo ADT

    push(prioridad: number, elemento: T): void{ //
        this.heap.push([prioridad, elemento]);
        this.bubbleUp(this.heap.length -1 );
    }

    pop() : NodoHeap<T> | undefined { // -> "|" es un tipo union, puede devolver dos cosas:
                                      //  NodoHeap<T> si hay elementos o undefined si no hay elementos 

        if(this.heap.length === 0) return undefined; /// c++ == vs Ts ===

        const raiz = this.heap[0];
        const ultimo = this.heap.pop()!; // se usa ! (operador de asercion no nula) para decir que
                                         //  estoy seguro que voy a devolver NodoHeap<T> en ese pop
                                         // Le dice al compilador: "Confía en mí, estoy 100% seguro de que este valor NO es null ni undefined".
                                         
        if (this.heap.length > 0){       // Si estuviera vacio no hariamos nada mas, ps la dejamos vacia
            this.heap[0] = ultimo;       // por si si hubiera cosas que orderar despues de modificar la pq
            this.bubbleDown(0);          // ps ahi si hacemos el bubbledown al arreglo segun el arreglo y que se elimino
        }
        return raiz;

    }


    get length(): number{ //define un getter (solo lectura calculada).
        return this.heap.length;
    }

    get isEmpty(): boolean {
        return this.heap.length === 0;
    }

    private bubbleUp(idx: number): void{
        while(idx > 0){
            const idxPadre = Math.floor((idx -1) / 2);

            if(this.heap[idx][0] >= this.heap[idxPadre][0] ) break; // heap[idx][0] accede a idx = del arrglo 
                                                                    // y accede a la prioridad de es nodo  [[0]] ->priodidad,elemento]
            
            [this.heap[idx], this.heap[idxPadre]] = [this.heap[idxPadre], this.heap[idx]];
            idx = idxPadre;
        }
    }

    private bubbleDown(idx: number): void{

        const n = this.heap.length;
        
        while(true){
            let menor = idx; //let variable mutable
            const izq = 2 * idx + 1;
            const der = 2 * idx + 2;

            if( izq < n && this.heap[izq][0] < this.heap[menor][0]) menor = izq;
            if( der < n && this.heap[der][0] < this.heap[menor][0]) menor = der;

            if(menor === idx) break;

            [this.heap[idx], this.heap[menor]] = [this.heap[menor] , this.heap[idx]];
            idx = menor;
        }
    }
}