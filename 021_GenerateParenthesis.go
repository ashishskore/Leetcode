var lstr []string
func  _parenthesis_generator(str []byte, pos int, n int, open int, close int)  {
	if(close == n){
		lstr = append(lstr, string(str))
		return
	} else {
		if(open > close) { 
			str[pos] = '}'; 
			_parenthesis_generator(str, pos+1, n, open, close+1); 
		} 
		if(open < n) { 
			str[pos] = '{'; 
			_parenthesis_generator(str, pos+1, n, open+1, close); 
		}
	}
}
func generateParenthesis(n int) []string {
	lstr = nil
	str := make([]byte,n*2)
	_parenthesis_generator(str, 0,n,0,0)
	return lstr 
}
