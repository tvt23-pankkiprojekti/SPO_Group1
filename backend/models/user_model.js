const db=require('../database');
const bcrypt=require('bcryptjs');

const user={
    getUser(id_user, callback){
        return db.query("SELECT fname, lname, state, temp_restriction FROM user WHERE id_user = ?", [id_user], callback);
    }, // for admins

    addUser(newUser, callback){
        bcrypt.hash(newUser.password, 10, function(err, hashedPassword){
            return db.query("INSERT INTO user(fname, lname, state, password) VALUES(?,?,?,?)", [newUser.fname, newUser.lname, newUser.state, hashedPassword], callback);
        });
    },

    login(id_user, callback) {
        return db.query("SELECT password FROM user WHERE id_user = ?", [id_user], callback);
    }, //verify correct pincode
    
    getUserByName(fname, lname, callback) {
        return db.query("SELECT id_user FROM user WHERE fname = ? AND lname = ?", [fname, lname], callback);
    }, // 

    updateUser(up, updateData, callback){
        bcrypt.hash(updateData.password, 10,function(err,hashedPassword){
            return db.query("UPDATE user SET fname=?, lname=?, state=?, temp_restriction=?, password=? WHERE id_user=?",
            [updateData.fname, updateData.lname, updateData.state, updateData.temp_restriction, hashedPassword, up], callback);
        });
    }, //for admins

    deleteUser(id_user, callback){
        return db.query("DELETE FROM user WHERE id_user=?", [id_user], callback); //for admins
    }
}
    
module.exports=user;

