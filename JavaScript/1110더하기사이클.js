let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split(' ');

let num = Number(input);
let cnt=1;
let num2=(num%10)*10+((Math.floor(num/10)+num%10))%10;

while(num!=num2){
    num2=(num2%10)*10+((Math.floor(num2/10)+num2%10))%10;
    cnt++;
}
console.log(cnt);