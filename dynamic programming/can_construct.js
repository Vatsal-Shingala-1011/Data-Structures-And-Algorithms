const canconstruct=(target,wordbank)=>
  {
    if(target==='') return true;
    for(let word of wordbank)
      {
        if(target.indexOf(word)===0){
          const suffix=target.slice(word.length);
          if(canconstruct(suffix,wordbank)===true){
            return true;
          }
        }
      }
    return false;
  }
console.log(canconstruct("abcdef",["ab","abc","cd","def","abcd"]));
console.log(canconstruct("skateboard",["bo","rd","ate","t","ska","sk","boar"]));
