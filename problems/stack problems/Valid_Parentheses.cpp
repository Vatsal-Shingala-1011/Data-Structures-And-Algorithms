// class Solution { //self
// public:
//     bool isValid(string s) {
//         stack <char> st;
//         int n=s.length();
//         for (int i=0;i<n;i++)
//         {
//             if(s[i]=='(' ||s[i]=='{' || s[i]=='[')
//             {
//                 st.push(s[i]);
//             }
//             else{
//                 if(!st.empty()){
//                 if( (st.top()=='(' && s[i]==')') || (st.top()=='{' && s[i]=='}')  || (st.top()=='[' && s[i]==']') )
//                 {
//                     st.pop();
//                 }
//                 else
//                 {
//                     return false;
//                 }
//                 }
//                 else {
//                     return false;
//                 }
//             }
//         }
//         if(st.empty())
//         {
//             return true;
//         }
//         return false;
//     }
// };