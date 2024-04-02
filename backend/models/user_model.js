const db=require('../database');
const bcrypt=require('bcryptjs');

const user={
    getUser(u, callback){
        return db.query("SELECT fname, lname, state, temp_restriction FROM user WHERE id_user = ?",[u], callback);
    }, // for admins

    updateUser(up,updateData, callback){
        bcrypt.hash(updateData.password, 10,function(err,hashedPassword){
            return db.query("UPDATE user SET fname=?, lname=?, state=?, temp_restriction=?, password=? WHERE id_user=?",
            [updateData.fname, updateData.lname, updateData.state, updateData.temp_restriction, hashedPassword, up],callback);
        });//for admins

    deleteUser(de, callback){
        return db.query("DELETE FROM user WHERE id_user=?",[de],callback); //for admins
        } 
        


