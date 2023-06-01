function trocar_fundo()
{
    
    
    trocar_aleatorio(change_css).then(()=>console.log("trocando cor!"))
}

const trocar_aleatorio = (trocar) => {
    return new Promise((resolve, reject) =>
    {
        setTimeout(()=>{
            let r = Math.floor(Math.random() * 100) + Math.floor(Math.random() * 50)
            let g = Math.floor(Math.random() * 100) + Math.floor(Math.random() * 50)
            let b = Math.floor(Math.random() * 100) + Math.floor(Math.random() * 50)

            trocar(r,g,b)
            resolve();
        }, 1000)
    })
}

function change_css(r,g,b)
{
    document.body.style = "background-color: rgb(" +r + " "+ g + " " +b +");";

}
