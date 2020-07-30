console.log("This is the first thing to type");
//alert("Received loud and clear");
//document.getElementById("pid").innerHTML = "Hello, this the new string"
/*var age = prompt("Enter the age: ");
document.getElementById("pid").innerHTML = "age = " + age

var num = 5.7;
console.log(5*10);
num++;
console.log(num);
printer("this is a string");
printer(56);
printer(true);
*/
//function:
/*
var k = prompt("Enter the number of fibonacci numbers to be printed: ");
factorial(k);
*/
function factorial(k)
{
    //js has no mention of the data type of the function arguments
    
    var a=1,f0=0,f1=1;
    console.log(f1);
    while(a <= k)
    {
        f1 += f0;
        f0 = f1-f0;
        printer(f1);
        a++;
    }
    //console.log(f1);
}
function printer(o)
{
    console.log(o);
}
//DATA TYPES
/*
let yourName = 18;// number
let yourAge = "bob";// string
let name = {first:"Pratyay",middle:"D",last:"Pande"};// object
console.log(name.first + " " + name.middle + " " + name.last);
*/
let fruit = ['apple','banana','pineapple','mango','strawberry','peach','squash'];

let morefruit = 'banana\napple';
console.log(fruit);
console.log(fruit[3]);
console.log(fruit.indexOf('banana'));
let onefruit = "banana";
console.log(onefruit.indexOf('an'));

//slicing:

console.log(fruit.slice(2,4));//slices: [firstindex,lastindex)
console.log(onefruit.slice(2,5));
console.log(onefruit.replace('an','pwqwerrew'));
//console.log(fruit.replace('banana','oranges'));
console.log(onefruit.toUpperCase());
var g = 'e';
g = g.toUpperCase();
console.log(g);
fruit = new Array('apple','banana','pineapple','mango','strawberry','peach','squash');
fruit[2] = "pear";
console.log(fruit);
let str = 'helloouu';

for(let i=0;i<fruit.length;i++)
    console.log(fruit[i]);

console.log("Testng phase:");
var k = prompt("Enter your age");
var h = (k < 18)? 1:2;
switch(h)
{
    case 1:
        alert("Age restricted");
        break;
    case 2:
        console.log("Age approved");
        break;
    default:
        console.log("Nope");
}
