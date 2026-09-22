function normalFibonnaci(n) {
    if (n === 0) {
        return 0;
    }
    if (n === 1) {
        return 1;
    }
    return (normalFibonnaci(n - 1) + normalFibonnaci(n - 2));
}
let dp = [0, 1];
function dpFibonacci(n) {
    if (n === 0) {
        return dp[0];
    }
    if (n === 1) {
        return dp[1];
    }
    dp[n] = dp[n - 1] + dp[n - 2];
    return dp[dpFibonacci(n - 1)] + dp[dpFibonacci(n - 2)];
}
console.log(normalFibonnaci(3));
console.log(dpFibonacci(3));
