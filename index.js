import express from 'express'
import bodyParser from 'body-parser'
import mongoose from 'mongoose'

const app=express();

let user=[]

app.use(bodyParser.json());

const PORT=5001;

let a={};
app.post( '/post', (req, res)=> {
    a=req.body;
    console.log(a)
    user.push(...user,a)
    //res.send(req.body)
})

app.get ('/post/:id', (req, res)=>{
    id = req.params;
    res.send(user.find((user)=> user.id))
})

app.delete('/post/:id', (req, res) => {
    // Handle the request
    const id = req.params.roll ;
    console.log(`Deleting resource ${id}`);
    res.send(`Deleted resource ${id}`);
  });

app.listen(PORT, () => console.log(`Server running on port : http://localhost:${PORT}`));