class Pessoa {
    constructor(nome, dia, mes, ano)
    {
        this.nome = nome
        this.dia = dia
        this.mes = mes
        this.ano = ano
    }

    get idade(){
        let anos = 2023 - this.ano
        if (5 - this.mes > 0){ 

            return anos;
        
            }
        if(5-this.mes == 0){
            if(18-this.dia <= 0) return anos;
            }
            return anos-1;
        return anos -1;
    }
}

function calcular_idade()
{   
    let nome = document.querySelector("#nome").value
    let dia = document.querySelector("#dia").value
    let mes = document.querySelector("#mes").value
    let ano = document.querySelector("#ano").value
    let pessoa = new Pessoa(nome, dia, mes, ano);

    document.querySelector("#idade").textContent = pessoa.idade
}

//// exercicio 2
class Cachorro {
    constructor(nome, idade, porte, cor)
    {
        this.nome = nome
        this.idade = idade
        this.porte = porte
        this.cor = cor
    }

}

var array_cachorro = []

function adicionar_cachorro()
{
    let nome = document.querySelector("#cachorro-nome").value
    let idade = document.querySelector("#cachorro-idade").value
    let porte = document.querySelector("#cachorro-porte").value
    let cor = document.querySelector("#cachorro-cor").value

    let cachorro = new Cachorro(nome, idade, porte, cor);

    array_cachorro.push(cachorro);
    let texto_array = ""
    for (let i = 0; i< array_cachorro.length; i++)
    {
        texto_array += "Cachorro " + (i+1) + ": " + array_cachorro[i].nome+ "; "
    }

    document.querySelector("#array-cachorro").textContent = texto_array;
}

// Exercicio 2

class Retangulo{
    constructor(altura, largura, cor)
    {
        this.altura = altura;
        this.largura = largura;
        this.cor = cor;
    }


}
var array_retangulo = []

function adicionar_retangulo()
{
    let altura = document.querySelector("#ret-altura").value
    let largura = document.querySelector("#ret-largura").value
    let cor = document.querySelector("#ret-cor").value

    let retangulo = new Retangulo(altura, largura, cor);

    array_retangulo.push(retangulo)
}

var c = document.querySelector("#retangulo-desenho")
var ctx = c.getContext("2d")

function desenhar_retangulo()
{
    for (let i = 0; i< array_retangulo.length; i++)
    {
        retangulo_atual = array_retangulo[i];
        ctx.beginPath();
        ctx.rect(20,20, 150, 100);
        ctz.stroke()

    }
}