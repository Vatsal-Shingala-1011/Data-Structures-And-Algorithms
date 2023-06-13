// // //brute force //revision left
// const bestsum = (targetsum, numbers) => {
//   if (targetsum === 0) return [];
//   if (targetsum < 0) return null;
//   let shortestcombination = null;
//   for (let num of numbers) {
//     const remainder = targetsum - num;
//     const remaindercombination = bestsum(remainder, numbers);
//     if (remaindercombination !== null) {
//       const combination =[...remaindercombination,num ];
//       if(shortestcombination === null || combination.length<shortestcombination.length)
//       {
//         shortestcombination=combination;
//       }
//     }
//   }
//   return shortestcombination;
// };
// console.log(bestsum(7, [2, 3]));
// console.log(bestsum(7, [5, 3, 4, 7]));
// console.log(bestsum(7, [2, 4]));
// console.log(bestsum(8, [2, 3, 5]));
// console.log(bestsum(300, [7, 14]));


//----------------------------------------------------------------------------------------------------------------------------------------------------

// // // memoized
// const bestsum = (targetsum, numbers,memo={}) => {
//   if (targetsum === 0) return [];
//   if (targetsum < 0) return null;
//   if(targetsum in memo) return memo[targetsum];
//   let shortestcombination = null;
  
//   for (let num of numbers) {
//     const remainder = targetsum - num;
//     const remaindercombination = bestsum(remainder, numbers,memo);
//     if (remaindercombination !== null) {
//       const combination =[...remaindercombination,num ];
//       // if currunt combination is shorter than the shortest combination then update it.
//       if(shortestcombination === null || combination.length<shortestcombination.length)
//       {
//         targetsum[num]=combination
//         shortestcombination=combination;
//       }
//     }
//   }
//   memo[targetsum]= shortestcombination;
//   return shortestcombination;
// };
// console.log(bestsum(7, [2, 3]));
// console.log(bestsum(7, [5, 3, 4, 7]));
// console.log(bestsum(7, [2, 4]));
// console.log(bestsum(8, [2, 3, 5]));
// console.log(bestsum(300, [7, 14]));

//----------------------------------------------------------------------------------------------------------------------------------------------------

// // //tabulation

const bestsum=(targetsum,numbers)=>
  {
    const table=Array(targetsum+1).fill(null);
    table[0]=[];
    for(let i=0;i<=targetsum;i++){
        if(table[i]!==null) 
        {
        for(let num of numbers)
          {
            const combination =[...table[i],num];
            if(!table[i+num]|| table[i+num].length > combination.length){
            table[i+num]=combination;
            }
          }
        }
      }
    return table[targetsum];
  };

console.log(bestsum(7,[2,3]));
console.log(bestsum(7,[5,3,4,7]));
console.log(bestsum(7,[2,4]));
console.log(bestsum(8,[2,3,5]));
console.log(bestsum(300,[7,14]));















