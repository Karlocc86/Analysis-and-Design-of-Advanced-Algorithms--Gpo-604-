


type Comparator<T> = (a: T, b: T) => number; 
const defaultCompare = <T>(a: T, b: T): number => (a < b) ? -1 : (a > b) ? 1 : 0;

function merge<T>(left: T[], right: T[], compare: Comparator<T>): T[]{

    const result: T[] = []
    let i = 0;
    let j = 0;

    while(i < left.length && j < right.length){
        
        if(compare(left[i], right[j]) <= 0){
            result.push(left[i]);
            i++;
        }else{
            result.push(right[j]);
            j++;
        }
    }

    while(right.length != j){
        result.push(right[j]);
        j++;
    }

     while(left.length != i){
        result.push(left[i]);
        i++;
    }

    return result;
}

export function mergeSort<T>(arr: T[], compare: Comparator<T> = defaultCompare): T[]{

    // BASE CASE: 0 or 2 elements - already sorted, stop recursion
    if( arr.length <= 1) return arr;

    // DIVIDE: split into two halves at the midpoint
    const mid = Math.floor(arr.length / 2);
    const left = arr.slice(0 , mid);
    const right = arr.slice(mid);

    //Conquer: recursively sort each half, then merge the sorted halfes
    return merge(mergeSort(left, compare),mergeSort(right, compare), compare);

}

function check(name: string, actual : unknown, expected:unknown): void{

    const a = JSON.stringify(actual);
    const e = JSON.stringify(expected);
    const pass = a === e;

    console.log(`${pass ? "Pass" : "Fail"} ${name}`);
    console.log(`   got:      ${a}`);
    if(!pass) console.log(`   expected: ${e}`);

}

check("ordena números", mergeSort([5, 2, 8, 1, 3]), [1, 2, 3, 5, 8]);
check("arreglo vacío", mergeSort([]), []);
check("un solo elemento", mergeSort([7]), [7]);