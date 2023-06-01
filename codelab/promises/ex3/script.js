function get_request()
{
    let url = "";
    fetch('https://api.thecatapi.com/v1/images/search')
    .then(response => response.json())
    .then(data => {
        url = data[0].url;
        let imagem = document.querySelector('#imagem')
        imagem.setAttribute('src', url)
        // console.log(data)
    })
    .catch(error => {
        console.log('erro ao dar fetch!');
    })


}