string longestCommonPrefix(vector<string> &arr, int n) {
  // Creating an answer string...
  string ans = "";

  //processing for the first string of the array...
  for (int i = 0; i < arr[0].length(); i++) {

    char ch = arr[0][i];
    bool match = true;
    for (int j = 1; j < n; j++) {

      //break if ch doesn't matches to other string chars...
      if (arr[j].size() < i || ch != arr[j][i]) {
        match = false;
        break;
      }
    }

    //if match is false break and stop evaluating...
    if (match == false) {
      break;
    }

    //Else push the char ch in the answer string...
    else {
      ans.push_back(ch);
    }
  }

  //At last return the ans...
  return  ans;
}
