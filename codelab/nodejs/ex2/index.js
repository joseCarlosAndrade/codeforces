const express = require('express')

const app = express()
const port = 3000

app.use(express.static("./public"))

app.get('/' , (req, res) =>
{
    res.send(__dirname + "/public/index.html")
})

app.listen(port, ()=>
{
   console.log(`Escutando nessa porta aqui: ${port}`) 
})