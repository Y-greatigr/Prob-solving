const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let input = [];

rl.on("line", function (line) {
  input.push(parseInt(line));
}).on("close", function () {
  
    if(Number(input[0])>0 && Number(input[1])>0)
        console.log(1);
    else if(Number(input[0])>0 && Number(input[1])<0)
        console.log(4);
    else if(Number(input[0])<0 && Number(input[1])>0)
        console.log(2);
    else
        console.log(3);
    process.exit();
});