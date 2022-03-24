const fs = require("fs");
const input = fs.readFileSync('/dev/stdin').toString().split('\n');

let x=[], y=[];

for(let i=0;i<3;++i) {
    x.push(Number(input[i].split(" ")[0]));
    y.push(Number(input[i].split(" ")[1]));
}
x=x.sort();
y=y.sort();

let row=x[0]===x[1]?x[2]:x[0];
let col=y[0]===y[1]?y[2]:y[0];

console.log(`${row} ${col}`);