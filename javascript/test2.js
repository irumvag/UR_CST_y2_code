function F1() {
    //console.log("F1");
    return 100;
}
function F2() {
    //console.log("F2");
    return 200;
}
a=F1()+F2();
console.log("the sum of F1 and F2: "+ a);
a=F1()*F2();
console.log("the product of F1 and F2: "+ a);
function F3(a=F1(), b=F2()) 
{
    return a + b;
}
console.log("the sum of F3: "+ F3());
function greeting(MyName) {      
    let text = "Hello " + MyName + "!";
    console.log(text); // prints out Hello Eric!
}

function greet(name, greetingFunction) {
        greeting(name);
    }
    greet("Eric")


    function sum(a, b) { return a + b; }
    function subtract(a, b) { return a - b; }
    
    // this is a higher-order function
    // the third parameter, operation, expects a function here
    function performOperation(a, b, operation) {
        return operation(a, b);
    }
    
    console.log(performOperation(4, 5, sum));
    // 9
    console.log(performOperation(10, 3, subtract));
    // 7
    function createGreater(greeting)
    {
        return function(name) {
            console.log(greeting + ", " + name+"!");
        }
    }
    const greetHello = createGreater("Bonjour ");
    const greetHi = createGreater("Hi");
    greetHello("Eric"); // prints out Hello, Eric
    greetHi("Eric"); // prints out Hi, Eric

    function addBy(add) {
        return function (value) {
          return value + add;
        };
      }
      
      const double = addBy(100);
      console.log(double(5))  
      const number=[1,2,3,4,5];
      const doubleNumber=number.map(number=>number*2);
      console.log(doubleNumber);

      const num=()=>Math.random();
        console.log(num());

    const sum1=number.reduce((accumulator, currentValue) => accumulator + currentValue, 0)
    console.log(sum1); // Output: 15
