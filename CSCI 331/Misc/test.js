function getSummation(upto){
    //TODO...
    let summation = 0; //var can stand in for let, let is block scoped and var is function scoped
    for (let i = 0; i<=upto; i++){
        summation += i;
    }
    return summation;
    
}

console.log(getSummation(100)) //5050