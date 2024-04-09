const db=require('../database');
const bcrypt=require('bcryptjs');

const user={
    getUser(user, callback){
        return db.query("SELECT fname, lname, state, temp_restriction FROM user WHERE id_user = ?", [user], callback);
    }, // for admins

    addUser(newUser, callback){
        bcrypt.hash(newUser.password, 10, function(err, hashedPassword){
            console.log(newUser);
            return db.query("INSERT INTO user(fname, lname, state, password) VALUES(?,?,?,?)", [newUser.fname, newUser.lname, newUser.state, hashedPassword], callback);
        });
    },
    
    getUserByName(fname, lname, callback) {
        return db.query("SELECT id_user FROM user WHERE fname = ? AND lname = ?", [fname, lname], callback);
    }, // When you enter a new user, the id is auto-increment and thus you won't know what it is, here you can search by name

    updateUser(up, updateData, callback){
        bcrypt.hash(updateData.password, 10,function(err,hashedPassword){
            return db.query("UPDATE user SET fname=?, lname=?, state=?, temp_restriction=?, password=? WHERE id_user=?",
            [updateData.fname, updateData.lname, updateData.state, updateData.temp_restriction, hashedPassword, up], callback);
        });
    }, //for admins

    deleteUser(uDelete, callback){
        return db.query("DELETE FROM user WHERE id_user=?", [uDelete], callback); //for admins
    }
}
    
module.exports=user;

