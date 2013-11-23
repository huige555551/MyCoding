import java.util.Stack;



class MyClass {
	
    public static void compute_palindromes(String[] words) {
   
        for(int i=0; i<words.length; i++){
        	int[] ch = new int[26];
        	
        	for(int j=0; j<words[i].length(); j++){
        		ch[words[i].charAt(j)-'a']++;
        	}
        	
        	int count = 0;
        	for(int j=0; j<26; j++){
        		if(ch[j]%2==1) count++;        		
        	}
        	
        	if(words[i].length()%2==1 && count!=1){
        		System.out.println("-1");        		
        	}        	
        	else if(words[i].length()%2==0 && count!=0){
        		System.out.println("-1");
        	}
        	else if (words[i].length()%2==1 && count==1){
        		char[] str = new char[words[i].length()];
        		
        		int j = 0;
        		for(int k=0; k<26; k++){
        			if(ch[k]==1) str[words[i].length()/2] = (char) ('a' + k);
        			else if (ch[k]!=0){
        				str[j] = (char) ('a' + k);
        				str[words[i].length()-1-j] = (char) ('a' + k);
        				j++;
        			}
        		}
        		System.out.println(new String(str));
        	}
        	else if(words[i].length()%2==0 && count==0){
        		char[] str = new char[words[i].length()];
        		int j = 0;
        		for(int k=0; k<26; k++){        			
    				if(ch[k]!=0){
    					str[j] = (char) ('a' + k);
    					str[words[i].length()-1-j] = (char) ('a' + k);
    					j++;
    				}
        		}
        		System.out.println(new String(str));
        	}
        	else{
        		System.out.println("-1");
        	}
        	
        	System.out.println(words[i]);        	
        }
        
    }
    
    public static void check_braces(String[] expressions) {
        
    	for(int i=0; i<expressions.length; i++){
    		
    		Stack<Character> stack = new Stack<Character>();
    		//boolean res = true;
    		
    		for(int j=0; j<expressions[i].length(); j++){
    			char ch = expressions[i].charAt(j);
    			
    			if(stack.isEmpty() || ch=='(' || ch=='[' || ch=='{') {
    				stack.push(ch); 
    			}
    			else{
    				if(ch == ')' && stack.peek()=='(') stack.pop();
    				else if(ch == '}' && stack.peek()=='{') stack.pop();
    				else if(ch == ']' && stack.peek()=='[') stack.pop();
    				else {
    					//res = false;
    					break;
    				}
    			}
    		}
    		if(stack.isEmpty()) System.out.println("1"); 
    		else System.out.println("0");
    	}
        
    }
    
    public static void roll_snake(Integer[] matrix, Integer width) {
        int[][] mat = new int[width][width];
        
        int k = 0;
    	for(int i=0; i<width; i++){
    		for(int j=0; j<width; j++){
    			mat[i][j] = matrix[k++];
    		}    		
    	}
    	
    	int layer;
    	for( layer=0; layer<width/2; layer++){
    		int first = layer;
    		int last = width - 1 -layer;
    		
    		for(int i= first; i<last; i++){
    			System.out.print(mat[first][i] + " ");
    		}
    		for(int i= first; i<last; i++){
    			System.out.print(mat[i][last]+" ");
    		}
    		for(int i= first; i<last; i++){
    			System.out.print(mat[last][last-i+first] + " ");
    		}
    		for(int i= first; i<last; i++){
    			System.out.print(mat[last-i+first][first] + " ");
    		}
    	}
    	if(width%2==1){
    		System.out.print(mat[layer][layer]);
    	}
    }
    
    public static void main(String[] args){
    	//String[] words = {"ivcci","oyotta","cecarar"};
    	//compute_palindromes(words);
    	//String[] words = { ")(){}", "[]({})", "([])", "{()[]}", "([)]" };
    	//check_braces(words);
    	Integer[] matrix = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
    	Integer width = 5;
    	roll_snake(matrix, width);
    	
    	System.out.println("\n");    	
    	Integer[] matrix2 = {1};
    	Integer width2 = 1;
    	roll_snake(matrix2, width2);
    	
    	System.out.println("\n");
    	Integer[] matrix3 = {1,2,3,4};
    	Integer width3 = 2;
    	roll_snake(matrix3, width3);
    	
    	System.out.println("\n");
    	Integer[] matrix4 = {1,2,3,4,5,6,7,8,9};
    	Integer width4 = 3;
    	roll_snake(matrix4, width4);
    	
    	System.out.println("\n");
    	Integer[] matrix5 = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    	Integer width5 = 4;
    	roll_snake(matrix5, width5);
    	
    	System.out.println("\n");
    	Integer[] matrix6 = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36};
    	Integer width6 = 6;
    	roll_snake(matrix6, width6);
    }
}