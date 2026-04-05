SCC (Strongly Connected Component) বের করার জন্য Kosaraju's Algorithm ব্যবহার করলে, transpose graph-এ starting node হবে সেই node যার finishing time সবচেয়ে বেশি আসল graph-এর DFS থেকে।

Kosaraju's Algorithm-এর ধাপ:
Step 1: আসল graph-এ DFS চালাও
প্রতিটি node-এর finishing time calculate করো

শেষে stack-এ node গুলো finishing time-এর উল্টো ক্রমে রাখো (অর্থাৎ যার finishing time বেশি, সে stack-এর উপরে)

Step 2: Graph-এর transpose করো (সব edge-এর direction উল্টাও)
Step 3: Transpose graph-এ DFS চালাও
Starting node: stack থেকে একে একে pop করে নাও (যার finishing time সবচেয়ে বেশি, সে প্রথমে আসবে)

প্রতিবার pop করা node থেকে transpose graph-এ DFS চালালে যে সব node visit হবে, তারা একটি SCC