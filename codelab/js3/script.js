let Cilindro = {
    altura : 0,
    raio : 0,
    volume: 0,
    
    calcularVolume: function() {
        this.volume = 3.1415 * this.altura * this.raio * this.raio
    }
}


function volumeCilindro()
{
    let raio = document.querySelector('#raio').value;
    let altura = document.querySelector('#altura').value;

    Cilindro.altura = altura
    Cilindro.raio = raio
    Cilindro.calcularVolume()
    let volume = Cilindro.volume

    document.querySelector("#resultado").textContent = volume
}


// exercicio 2

var array_nomes = []
var array_obj = []

function addObject()
{
    let nome = document.querySelector('#nome').value;
    let idade = document.querySelector('#idade').value;
    let peso = document.querySelector('#peso').value;
    
    let pessoa = {
        nome : nome,
        idade : idade,
        peso : peso
    }

    array_nomes.push(pessoa.nome)
    array_obj.push(pessoa)

    
    document.querySelector("#array").textContent = array_nomes
    alert("Adicionado novo elemento com Nome: " + pessoa.nome + "; Idade: " + pessoa.idade + "; Peso: " + pessoa.peso);

    checkPeople()
}

var maior_que_42_anos = 0;
var menor_que_18_anos = 0;
var menos_que_50_kilos = 0;
function checkPeople()
{
    maior_que_42_anos = 0;
    menor_que_18_anos = 0;
    menos_que_50_kilos = 0;
    for (let i = 0; i < array_obj.length; i++)
    {
        let pessoa = array_obj[i]
        console.log(pessoa.idade)
        if (pessoa.idade > 42) {maior_que_42_anos += 1;}
        if (pessoa.idade < 18) {menor_que_18_anos += 1;}
        if (pessoa.peso < 50) {menos_que_50_kilos += 1;}
    }

    document.querySelector("#relatorio").textContent = "Há " + maior_que_42_anos + " pessoas maiores que 42 anos, " + menor_que_18_anos + " menores que 18 e " + menos_que_50_kilos + " pessoas com menos de 50 kilos."
}

function slice()
{
    let string = document.querySelector("#string").value;;
    let size = string.length;
    let array_of_slices = []
    for (let i = 0; i < size; i++)
    {
        for (let j = 1; j < size+1; j++){
            let slice = string.slice(i,j)
            if (slice == "") continue; 
            array_of_slices.push(slice)
        }
    }

    document.querySelector("#slice-show").textContent = array_of_slices
}