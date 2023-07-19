import heapq
import os

class BinaryTree: 
    def __init__(self,val,freq):
        self.val=val #store value(binary)
        self.freq=freq #freq
        self.left=None
        self.right=None
        
    def __lt__(self,other):
        return self.freq < other.freq
    
    def __eq__(self,other):
        return self.freq==other.freq

class Huffmancode:
    def __init__(self,path):
        self.path=path
        self.__char_heap=[] #min heap-store char in heap according to frequency
        self.__code_dict={} #dict that contain binary representation for each char
        self.__code_to_char_dict={}
    def __fre_cnt(self,text):
        fre_dict={}  # dictionary of fre of char
        for char in text:
            if char not in fre_dict:
                fre_dict[char]=0
            fre_dict[char]+=1
        return fre_dict
    
    def __build_heap(self,freq_dict):
        for key in freq_dict:
            heapq.heappush(self.__char_heap, BinaryTree(key,freq_dict[key]))# lt and eq we define function above so heap push BinaryTree node according to it
                        # push BinaryTree node into __heap(that we definr in init )
    def __build_BT(self):
        while len(self.__char_heap)>1:
            min1=heapq.heappop(self.__char_heap) # two smallest node from heap
            min2=heapq.heappop(self.__char_heap)###################cheak self.__heap.heappop()
            newnode=BinaryTree(None,min1.freq+min2.freq)
            newnode.left=min1
            newnode.right=min2  
            heapq.heappush(self.__char_heap, newnode)
        return
        
    def __abstract_char_code(self,root,bits_str):
        if root.val is not None: #only leef node contain value #no node left or right to node that contain val 
            self.__code_dict[root.val]=bits_str
            self.__code_to_char_dict[bits_str]=root.val
            return
        self.__abstract_char_code(root.left,bits_str+"0")
        self.__abstract_char_code(root.right,bits_str+"1")
        
    def __encode(self,text):
        encoded_str=""
        for char in text:
            encoded_str+=self.__code_dict[char]
        return encoded_str
    
    def __do_padding(self,encoded_text):
        val=8-len(encoded_text)%8 
        for i in range(val): # so that string can divide in to bit of 8 
            encoded_text+='0'
        first="{0:08b}".format(val) # binary string of val of len 8 
        return first+encoded_text
        
    def __final_coded_array(self,padded_text):
        array=[]
        for i in range(0,len(padded_text),8):
            hexa_str=padded_text[i:i+8]
            array.append(int(hexa_str,2))
        return array
        
    def compression(self):
        filename,extention =os.path.splitext(self.path)
        output_path =filename+'.bin'
        with open(self.path,'r+') as file,open(output_path,'wb') as output:
            text=file.read()
            text=text.rstrip() #remove extra spaces
            #count of frequence of char in string
            freq_dict=self.__fre_cnt(text)
            #creating a heap to store char according to freq
            char_heap = self.__build_heap(freq_dict)
            #creating binary tree according to frequncy of each node
            self.__build_BT()
            #Now abstract value for each node in binary form from BT that we construct above and store in dictionary
            self.__abstract_char_code(heapq.heappop(self.__char_heap), '')# char_heap contain only one elemet
                                        ## root                     ,bits_str
            #Now construct encoded text from abstract char code
            encoded_text= self.__encode(text)
            
            #adding padding to this encoded text
            padded_text=self.__do_padding(encoded_text)
            #Now convert this padded text into arry of hexa number
            final_coded_array=self.__final_coded_array(padded_text)
            final_op=bytes(final_coded_array)
            output.write(final_op)
#             print(encoded_text)
#             print()
#             print(padded_text)
        return output_path
    
    def __Remove_padding(self,text):
        val= int(text[:8],2)
        print(val)
        text=text[8:]
        text=text[:-1*val]
#         print("remove_padd",text)
        return text
    
    def __Decoded_text(self,text):
        curr_bits=""
        decoded_text=""
        for char in text:
            curr_bits+=char
            if curr_bits in self.__code_to_char_dict:
                decoded_text+=self.__code_to_char_dict[curr_bits]
                curr_bits=""
        return decoded_text 
    
    #0XB3F1-->integer form(ord function to convert hexa to int)-->binary(bin function to convert int to binary )
    def decompress(self,input_path):
        filename,file_extention =os.path.splitext(input_path)
        output_path=filename+'_decompressed' +'.txt'
        with open(input_path,'rb') as file,open(output_path,'w') as output:
            bit_string=""
            byte=file.read(1) #read one byte eachtime 1byte=8bit(00000000)
            while byte:
                byte =ord(byte) #In this line, you read one byte (8 bits) from the file and convert it to its corresponding ASCII value using the ord() function. The byte variable will store this ASCII value.
                bits =bin(byte)[2:].rjust(8,'0') #The bin(byte) function converts the ASCII value (integer) stored in byte into its binary representation. The output will have the prefix "0b" followed by the actual binary digits. For example, if byte is 72 (ASCII value of 'H'), then bin(byte) would return '0b1001000'. Next, [2:] is used to remove the '0b' prefix, so bits will contain only the binary digits ('1001000' in the example). The rjust(8, '0') method right-justifies the binary string by adding leading zeros to ensure that the final length of the binary string is exactly 8 bits. For example, if bits is '1001000', rjust(8, '0') will add three leading zeros to make it '01001000'.
                bit_string +=bits
                byte=file.read(1)
            #Now we have to remove padding
            Removing_padding=self.__Remove_padding(bit_string)
            actual_text=self.__Decoded_text(Removing_padding)
            print()
            print("actual_text :",actual_text)
            output.write(actual_text)
        return output_path
path =input("Enter Path: ")
h=Huffmancode(path)   
compressed_file=h.compression()
h.decompress(compressed_file)