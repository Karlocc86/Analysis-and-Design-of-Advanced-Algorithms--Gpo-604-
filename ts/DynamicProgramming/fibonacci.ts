
function normalFibonnaci(n: number): number{

    if(n === 0){
        return 0;
    }
    if(n === 1){
        return 1;
    }

    return (normalFibonnaci(n - 1) + normalFibonnaci(n-2));
}

let dp : number[] = [0,1];

function dpFibonacci(n : number): number{

    if(n === 0 ){
        return dp[0];
    }
    if(n === 1){
        return dp[1];
    }

    if(dp[n]) return dp[n];
    
    dp[n] = dpFibonacci(n - 1) + dpFibonacci(n -2);
    
    return dp[n];

}



function dpMapfibonnaci(n: number, memo : Map<number,number> = new Map()) : number{

    if(n <= 1)  return n;

    const cached = memo.get(n);

    if(cached !== undefined) return cached;
    
    const result = dpMapfibonnaci(n - 1, memo) + dpMapfibonnaci(n-2, memo);
    memo.set(n, result);

    return result;

    
}

function fibTab(n:number) : number{
    if(n <= 1) return n;
    const table: number[] = new Array(n+1);
    table[0] = 0;
    table[1] = 1;
    for(let i = 2; i <= n; i++){

        table[i] = table[i-1] + table[i -2];
    }

    return table[n];
}


console.log(normalFibonnaci(10));
console.log(dpFibonacci(100));

let dpMap : Map<number,number> = new Map();

console.log(dpMapfibonnaci(100,dpMap));

console.log(fibTab(100))