void decode_huff(node * root,string s)
{
   node *temp=root;
   for(int i=0;i<s.length();i++)
   {
       if(s[i]=='0')temp=temp->left;
       else temp=temp->right;
       if(temp->data)
       {
           printf("%c",temp->data);temp=root;
       }
      
   }
}
