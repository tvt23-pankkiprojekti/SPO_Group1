const db=require('../database');
const bcrypt=require('bcryptjs');

const admin={

    adminLogin(alg, callback){
        return db.query("SELECT admin_password FROM admin WHERE id_admin = ?", [alg], callback);
    }, //verify correct password for admin

    adminVerify(av,  callback){
        return db.query("SELECT temp_restriction FROM admin WHERE id_admin = ?", [av], callback);
    }, //admin login verify

    checkRights(ar, callback){
        return db.query("SELECT admin_rights FROM admin WHERE id_admin = ?", [ar], callback);
    }, // check admins rights

}
module.exports=admin;