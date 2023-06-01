async function printPokemon(pokemon)
{
    let response = await fetch(`https://pokeapi.co/api/v2/pokemon/${pokemon}`).catch((error)=>{
        console.log("Fetch error. " + error);
        return;
    });

    if (response.ok){
        let json = await response.json().catch((error)=> {
            console.log("JSON error. " + err);
        });

        let url = json.sprites.front_default;
        console.log(url)
        adicionarImagem(url);
    }
    else
    {
        alert('Pokemon nao encontrado!')

    }
}

function removerTudo()
{
    let parent = document.querySelector('#imagens');
    while (parent.firstChild)
    {
        parent.removeChild(parent.firstChild);
    }
}

function adicionarImagem(url)
{
    let image = document.querySelector("#imagens");

    let img = document.createElement('img',  { src: url})
    img.setAttribute('src', url);
    image.appendChild(img)
}

function inserirPokemon()
{   
    let pokemon = document.querySelector("#pokemon-input").value
    printPokemon(pokemon);
}
