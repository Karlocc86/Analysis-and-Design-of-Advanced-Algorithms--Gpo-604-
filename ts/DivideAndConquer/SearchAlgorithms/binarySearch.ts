type Comparator<T> = (a: T, b: T) => number; 
const defaultCompare = <T>(a: T, b: T): number => (a < b) ? -1 : (a > b) ? 1 : 0;


export function binarySearchRecursive<T>(

    arr: T[],
    target: T,
    compare: Comparator<T> = defaultCompare,
    lo = 0,
    hi = arr.length - 1
): number {

    // BASE CASE

    if( lo > hi) return -1;

    const mid = lo + Math.floor((hi-lo)/2)
    const cmp = compare(arr[mid], target);

    if( cmp === 0) return mid;
    return cmp < 0
        ? binarySearchRecursive(arr, target, compare, mid + 1, hi)
        : binarySearchRecursive(arr, target, compare, lo, mid - 1);
}
