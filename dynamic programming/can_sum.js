// // //brute force
const cansum=(targetsum,numbers)=>
  {
    if(targetsum===0) return true;
    if(targetsum<0)return false;
    for (let num of numbers) {
      const remainder=targetsum-num;
      if(cansum(remainder,numbers)===true)
      {
        return true;
      }
    }
    return false;
  };
console.log(cansum(7,[2,3]));
console.log(cansum(7,[5,3,4,7]));
console.log(cansum(7,[2,4]));
console.log(cansum(8,[2,3,5]));
console.log(cansum(300,[7,14]));


//----------------------------------------------------------------------------------------------------------------------------------------------------

// // // memoized
// const cansum=(targetsum,numbers,memo={})=>
//   {
//     if(targetsum===0) return true;
//     if(targetsum<0)return false;
//     if(targetsum in memo)return memo[targetsum];
//     for (let num of numbers) {
//       const remainder=targetsum-num;
//       if(cansum(remainder,numbers,memo)===true)
//       {
//         // memo[targetsum]=true; //// no need to write because when is is true its return 
//         return true;
//       }
//     }
//     memo[targetsum]=false;
//     return false;
//   };
// console.log(cansum(7,[2,3]));
// console.log(cansum(7,[5,3,4,7]));
// console.log(cansum(7,[2,4]));
// console.log(cansum(8,[2,3,5]));
// console.log(cansum(300,[7,14]));

//----------------------------------------------------------------------------------------------------------------------------------------------------

//tabulation

// const cansum=(targetsum,numbers)=>
//   {
//     const table=Array(targetsum+1).fill(false);
//     table[0]=true;
//     for(let i=0;i<=targetsum;i++)
//       {
//         if(table[i]===true) 
//         {
//         for(let num of numbers)
//           {
//             table[i+num]=true;
//           }
//         }
//       }
//     return table[targetsum];
//   };

// console.log(cansum(7,[2,3]));
// console.log(cansum(7,[5,3,4,7]));
// console.log(cansum(7,[2,4]));
// console.log(cansum(8,[2,3,5]));
// console.log(cansum(300,[7,14]));















