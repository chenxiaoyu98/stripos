int stripos(char *haystack, char *needle, int offset)
{
	int i = 0, j = 0, position = 0;
	
	//Convert two strings to lowercase to achieve case insensitive.
	while (haystack[i] != '\0') {
		if (haystack[i] >= 'A' && haystack[i] <= 'Z') {
			haystack[i] = haystack[i] + 32;
		}
		i++;
	}
	while (needle[j] != '\0') {
		if (needle[j] >= 'A' && needle[j] <= 'Z') {
			needle[j] = needle[j] + 32;
		}
		j++;
	}

	
	//Find needle in haystack.
	for (i = offset, j = 0;haystack[i] != '\0';i ++){
		if (haystack[i] == needle[j]) {
			if (j == 0){
				position = i;       //Store the position of the first occurence.
			}
			j ++;
			if (needle[j] == '\0'){
				return position;   //Return position if all the elements are compared.
			}
		}
		else{
			if (j != 0){
				i = position;	  //Return back to the position if the rest are not the same.
			}
			j = 0;
		} 
	}
	return -1;
}
