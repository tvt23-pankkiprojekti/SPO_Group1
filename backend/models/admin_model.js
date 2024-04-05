const db=require('../database');
const bcrypt=require('bcryptjs');

const admin={

    adminLogin(adminLog, callback){
        return db.query("SELECT admin_password FROM admin WHERE id_admin = ?", [adminLog], callback);
    }, //verify correct password for admin

    adminVerify(aVerify,  callback){
        return db.query("SELECT temp_restriction FROM admin WHERE id_admin = ?", [aVerify], callback);
    }, //admin login verify

    checkRights(aRights, callback){
        return db.query("SELECT admin_rights FROM admin WHERE id_admin = ?", [aRights], callback);
    }, // check admins rights

}

module.exports=admin;