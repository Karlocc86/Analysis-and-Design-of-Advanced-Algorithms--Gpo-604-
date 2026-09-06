
const list : number[] = [8,2,2,4,7,1,3,9,6,5,10,11,12,13,14,15]
const right : number = list.length -1;

function swap(list: number[], a:number, b:number): void{

    const temp : number = list[a];
    list[a] = list[b];
    list[b] = temp;
    
}

function conquer(list : number[], left : number, right: number): number{

    const pivote: number = list[right];
    let orange: number = left - 1;

    for( let green = left; green <= right ; green++){

        if(list[green] <= pivote){

            orange++;
            if(green > orange){
                swap(list, green, orange);
            }
        }
    }

    return orange;

}

export function divide(list: number[], left: number, right:number): void{

    if(left < right){

        const pivote : number = conquer(list, left, right)
        divide(list, left, pivote - 1)
        divide(list, pivote + 1 , right)
    }

}

console.log("La lista antes del sort=", list)

divide(list, 0 , right)

console.log("La lista despues del sort=", list)