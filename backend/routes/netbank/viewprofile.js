var user=require('../../models/user_model');
var account=require('../../models/account_model');

const profile = {
  getData(request, response) {
    let userid = request.cookies.simulbankuserid;

    if (1==0) {
      response.send("No user ID sent");
      return;
    }
    
    let answer = [];

    user.getUser(userid, function(err,result){
    if(err){
      response.send(err);
      return;
    }
    else{
      answer.push(result);
      console.log(result);
    } 
    
    account.allAccountsByUser(userid, function(err,result){
      if(err){
        response.send(err);
        return;
      }
      else{
        answer.push(result);
        console.log(result);
      }  
      response.send(answer);

      /* transaction.getTransHistory(userid, function(err,result){
        if(err){
          answer.push(err);
        }
        else{
          answer.push(result);
          console.log(result);
        } 
        response.send(answer);
        })*/
      });
    });
  }
}

module.exports=profile;