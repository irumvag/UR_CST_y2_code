function add1to10(n=0){
    if(n==10){
        return n;
    }
    return n + add1to10(n+1);
}
console.log("the sum of 1 to 10: "+ add1to10());
