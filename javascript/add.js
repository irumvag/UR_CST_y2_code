function add(a,b)
{
    return a+b;
}
let m=a=>{
    if(a>0){
        let sum=0;
        for(i=0;i<a;i++){
            sum+=i;
        }
        return sum;}
    else if(a==0){
        return 0;
    }
    else{
        return 0;
    }
}
console.log("The sum of 20+5=" + m(20));
console.log("The sum of 20+5=" + m(5));
const num=[1,2,3,4,5];
const doubleNum=num.map(num=>num*2);
console.log("num*2=["+doubleNum);
console.log("num=["+num);
const tripleNum=num.map(num=>num*3+num);
console.log("num*3+num["+tripleNum);
const filterNum=num.filter(num=>num>1);
const sum=num.reduce((acc,cur)=>{ return acc+cur;});
console.log("sum of num="+sum);
// The reduce function can be used for many operations, such as:
// - Summing all elements (as above)
// - Multiplying all elements: num.reduce((acc, cur) => acc * cur)
// - Finding the maximum: num.reduce((acc, cur) => Math.max(acc, cur))
// - Finding the minimum: num.reduce((acc, cur) => Math.min(acc, cur))
// - Concatenating strings: ['a','b','c'].reduce((acc, cur) => acc + cur)
// - Counting occurrences: arr.reduce((acc, cur) => { acc[cur] = (acc[cur] || 0) + 1; return acc; }, {})
function minimum(num){
    if(num.length==0){
        return 0;
    }
    return num.reduce((acc, cur) => Math.min(acc, cur));
}
nums=[0.1,2,45,6,65,8,688,8,8,9,34,5,3,2,1];
console.log("minimum of num="+minimum(nums));
const fliternum=nums.filter(nums=>nums>5);
console.log("num>5=["+fliternum);
const areallnumpositive=nums.every(nums=>nums>0);
console.log("are all num positive?"+areallnumpositive);
nums.sort((a,b)=>a-b);
console.log("sorted num=["+nums);
class Umukozi {
    constructor(indangamuntu, izina, umushahara) {
        this.indangamuntu = indangamuntu; // Integer
        this.izina = izina; // Text
        this.umushahara = umushahara; // Double
    }

    // Setters
    setIndangamuntu(indangamuntu) {
        this.indangamuntu = indangamuntu;
    }

    setIzina(izina) {
        this.izina = izina;
    }

    setUmushahara(umushahara) {
        this.umushahara = umushahara;
    }

    // Getters
    getIndangamuntu() {
        return this.indangamuntu;
    }

    getIzina() {
        return this.izina;
    }

    getUmushahara() {
        return this.umushahara;
    }

    // Additional method to display employee details
    displayInfo() {
        return `INDANGAMUNTU: ${this.indangamuntu}, Izina: ${this.izina}, Umushahara: $${this.umushahara.toFixed(2)}`;
    }
}

// Example usage:
const emp1 = new Umukozi(1, "Yohwana Vumbi", 50000.5);
emp1.setIndangamuntu(120048006252601);
console.log(emp1.displayInfo());
class umuryi{
    constructor(izina,ibiryo,igiciro){
        this.izina=izina;
        this.ibiryo=ibiryo;
        this.igiciro=igiciro;
    }
    setIzina(izina){
        this.izina=izina;
    }
    setIbiryo(ibiryo){
        this.ibiryo=ibiryo;
    }
    setIgiciro(igiciro){
        this.igiciro=igiciro;
    }
    getIzina(){
        return this.izina;
    }
    getIbiryo(){
        return this.ibiryo;
    }
    getIgiciro(){
        return this.igiciro;
    }
    displayInfo(){
        return `IZINA: ${this.izina}, IBIRYO: ${this.ibiryo}, IGICIRO: $${this.igiciro.toFixed(2)}`;
    }
}
class umunywi{
    constructor(izina,ibinyobwa,igiciro){
        this.izina=izina;
        this.ibinyobwa=ibinyobwa;
        this.igiciro=igiciro;
    }
    setIzina(izina){
        this.izina=izina;
    }
    setIbinyobwa(ibinyobwa){
        this.ibinyobwa=ibinyobwa;
    }
    setIgiciro(igiciro){
        this.igiciro=igiciro;
    }
    getIzina(){
        return this.izina;
    }
    getIbinyobwa(){
        return this.ibinyobwa;
    }
    getIgiciro(){
        return this.igiciro;
    }
    displayInfo(){
        return `IZINA: ${this.izina}, IBINYOBWA: ${this.ibinyobwa}, IGICIRO: $${this.igiciro.toFixed(2)}`;
    }
}
const umuryi1 = new umuryi("Vumvu", "Umuceri,ibirayi,ifiriti", 5000);
const umunywi1 = new umunywi("Sebigori", "Byeri,fanta,mitzig", 5000);
console.log(umuryi1.displayInfo());
console.log(umunywi1.displayInfo());
const totaligiciro=umuryi1.igiciro+umunywi1.igiciro;
console.log("Igiciro cyose ni: $"+totaligiciro);