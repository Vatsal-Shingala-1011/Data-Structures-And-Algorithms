// // //brute force
const howsum = (targetsum, numbers) => {
  if (targetsum === 0) return [];
  if (targetsum < 0) return null;
  for (let num of numbers) {
    const remainder = targetsum - num;
    const remainderresult = howsum(remainder, numbers);
    if (remainderresult !== null) {
      return [...remainderresult, num];    ///// each step of out of recursion add num
    }
  }
  return null;
};
console.log(howsum(7, [2, 3]));
console.log(howsum(7, [5, 3, 4, 7]));
console.log(howsum(7, [2, 4]));
console.log(howsum(8, [2, 3, 5]));
console.log(howsum(300, [7, 14]));


//----------------------------------------------------------------------------------------------------------------------------------------------------

// // // memoized
// const howsum = (targetsum, numbers,memo={}) => {
//   if (targetsum === 0) return [];
//   if (targetsum < 0) return null;
//   if (targetsum in memo) return memo[targetsum];
//   for (let num of numbers) {
//     const remainder = targetsum - num;
//     const remainderresult = howsum(remainder, numbers,memo);
//     if (remainderresult !== null) {
//       return [...remainderresult, num];    ///// each step of out of recursion add num
//     }
//   }
//   memo[targetsum]=null;
//   return null;
// };
// console.log(howsum(7, [2, 3]));
// console.log(howsum(7, [5, 3, 4, 7]));
// console.log(howsum(7, [2, 4]));
// console.log(howsum(8, [2, 3, 5]));
// console.log(howsum(300, [7, 14]));

//----------------------------------------------------------------------------------------------------------------------------------------------------

// // //tabulation

// const howsum=(targetsum,numbers)=>
//   {
//     const table=Array(targetsum+1).fill(null);
//     table[0]=[];
//     for(let i=0;i<=targetsum;i++)
//       {
//         if(table[i]!==null) 
//         {
//         for(let num of numbers)
//           {
//             table[i+num]=[...table[i],num];
//           }
//         }
//       }
//     return table[targetsum];
//   };

// console.log(howsum(7,[2,3]));
// console.log(howsum(7,[5,3,4,7]));
// console.log(howsum(7,[2,4]));
// console.log(howsum(8,[2,3,5]));
// console.log(howsum(300,[7,14]));















