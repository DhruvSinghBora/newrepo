import express from 'express'
import bodyParser from 'body-parser'
import mongoose from 'mongoose'
mongoose.set('strictQuery',false);
mongoose.connect("mongodb://127.0.0.1:27017/Document").then(function(){
    console.log("Connection Established are u sure");
}).catch(function(err){
    console.log(err)
})

const app=express();

app.use(bodyParser.json());

const PORT=5000;

const schema = {
    name: {type: String},
    roll : {type: Number, unique: true, required: true}
}

const item = mongoose.model('item', schema)


app.post('/',function(req,res){
    const item1= new item({
        name: req.body.name, 
        roll: req.body.roll
    })
    item1.save().then(function(){
        res.send("USER ADDED");
    }).catch(function(err){
        res.send("USER Already exist");

    });
   
    
})

app.get('/:id', (req, res) => {

    item.find(function(err, details) {

        if (err) return console.error(err);

        res.send(details);

    });

});

app.listen(PORT, () => console.log(`Server running on port : http://localhost:${PORT}`));
