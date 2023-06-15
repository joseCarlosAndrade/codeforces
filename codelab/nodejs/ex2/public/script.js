var nome_salvo = ""

function load_body()
{
    if (document.cookie) 
    {
        cadastro = JSON.parse(document.cookie.slice(("cadastro=").length))
        console.log(cadastro)
        document.querySelector("#boas-vindas").textContent = `Olá ${cadastro.usuario}!`
    }
}

function salvar_nome()
{
    nome = document.querySelector("#nome").value
    senha_form = document.querySelector("#senha").value
    if (nome == '') 
    {
        alert("Nome invalido!")
        return ;
    }
    let cadastro = {
        usuario : nome,
        senha : senha_form
    }
    // console.log(cadastro)

    // document.cookie = `cadastro=${nome}; expires=Wed, 21 Jun 2023 13:00:00 UTC`
    document.cookie = "cadastro=" + JSON.stringify(cadastro) + "; expires=Wed, 21 Jun 2023 13:00:00 UTC"
    // nome_salvo = nome;
    alert("Nome salvo!")
    // console.log(document.cookie)

}

function esquecer_nome()
{
    nome_salvo = ""
    alert("Nome esquecido!")
    document.cookie = `cadastro=${nome_salvo}; expires=Wed, 21 Jun 2020 13:00:00 UTC`
    // console.log(document.cookie)
    location.reload()
}