//  //  //brute force
// const gridtraveler = (m, n) => {
//   if (m === 1 && n === 1) return 1;
//   if (m === 0 || n === 0) return 0;
//   return gridtraveler(m - 1, n) + gridtraveler(m, n - 1);
// };

// console.log(gridtraveler(2, 2));
// console.log(gridtraveler(2, 3));
// console.log(gridtraveler(5, 6));
// console.log(gridtraveler(3, 3));

//----------------------------------------------------------------------------------------------------------------------------------------------------------
// 

//
// // // memoized
// const gridtraveler = (m, n,memo={}) => {
//   const key=m+','+n;
//   if(key in memo) return memo[key];
//   if (m === 1 && n === 1) return 1;
//   if (m === 0 || n === 0) return 0;
//   memo[key]=gridtraveler(m-1,n,memo)+gridtraveler(m, n - 1,memo);
//   return gridtraveler(m-1,n,memo)+gridtraveler(m, n - 1,memo);;
// };
// //m=42
// //n=3
// //key = 423 if we didnt put ' , '
// //key = 42,3 if put ' , '
// console.log(gridtraveler(2, 2));
// console.log(gridtraveler(2, 3));
// console.log(gridtraveler(5, 6));
// console.log(gridtraveler(35, 312));

//
//----------------------------------------------------------------------------------------------------------------------------------------------------------

// // // tabulation error

const gridtraveler = (m, n) => {
 const table=Array(m+1)
   .fill()
   .map(()=>Array(n+1).fill(0)); //map every element of array to n+1 size array
 // const table=Array(m+1)
 //   .fill(Array(n+1));
  table[1][1]=1;
  for(let i=0;i<=m;i++){
      for(let j=0;i<=n;j++){  
        const curr=table[i][j];
        if(j +1<=n) table[i][j+1]+=curr;
        if(i +1<=m) table[i+1][j]+=curr;
      
      }
    }
  return table[m][n];
};

console.log(gridtraveler(2, 2));
// console.log(gridtraveler(2, 3));
// console.log(gridtraveler(5, 6));
// console.log(gridtraveler(3, 3));