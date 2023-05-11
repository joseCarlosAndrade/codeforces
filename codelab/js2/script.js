
function calcular() 
{
    let a = parseFloat(document.querySelector('#operando1').value);
    let b = parseFloat(document.querySelector('#operando2').value);

    let c = document.querySelector('#operacao').value;

    switch (c) {
        case '+':
            document.querySelector('#resultado').textContent = a+b;
            break;

        case '-':
            document.querySelector('#resultado').textContent = a-b;
            break;

        case '*':
            document.querySelector('#resultado').textContent = a*b;
            break;

        case '/':
            document.querySelector('#resultado').textContent = a/b;
            break;

        default:
            alert("Operaçao invalida!");
            break;
    }
}

var array = [];

function Add()
{
    array.push(document.querySelector('#array').value)
}

function Display()
{
    let array_text = ''
    for (let i = 0; i < array.length; i++)
    {   
        array_text += '<p> Elemento '+ i +': ' + array[i] + '</p> ';
    }

    document.querySelector('#display-array').innerHTML   = array_text
}

var img_array = ['img/bolt.jpg', 'img/zelda.jpg', 'img/mario.jpg']
let image = document.querySelector('#img_array')
// let image = document.getElementById("img-a")
var i = 0;
function swapImage()
{
    // i = i%3;
    img_src = img_array[i%3];
    i = i +1;
    image.setAttribute('src', img_src);
}

setInterval(swapImage, 200);