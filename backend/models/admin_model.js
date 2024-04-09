const db=require('../database');
const bcrypt=require('bcryptjs');

const admin={

    adminLogin(id, callback){
        return db.query("SELECT admin_password FROM admin WHERE id_admin = ?", [id], callback);
    }, //verify correct password for admin

    adminVerify(id,  callback){
        return db.query("SELECT temp_restriction FROM admin WHERE id_admin = ?", [id], callback);
    }, //admin login verify

    checkRights(id, callback){
        return db.query("SELECT admin_rights FROM admin WHERE id_admin = ?", [id], callback);
    }, // check admins rights

}

module.exports=admin;