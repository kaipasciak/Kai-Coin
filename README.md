Author: Kai Pasciak

This project, entitled KaiCoin, is a simplified demonstration of how a blockchain network works in the context of 
Decentralized Finance or DeFi. There are classes each for blocks that make up the blockchain, nodes, wallets, 
transactions and the blockchain itself. A constructor for the blockchain will create a genesis block, and is an 
object that represents the entire network including wallets and participating nodes, rather than just the blockchain.

The main program will prompt the user to add as many wallets and nodes to the network as desired. The user can simulate 
transactions on the network by creating transactions, choosing the sender, recipient and amount. The mempool is 
designed to add three transactions to a new block for simplicity's sake. Nodes compete to solve blocks using a PoW
(Proof of Work) consensus mechanism. Transactions where the sender doesn't have a sufficient balance to fulfill it will
not be fulfilled. In a real blockchain, the nodes would have an associated wallet that would receive payments in the 
blockchain's currency as a reward. But for this project, the amount earned is stored in a field in their class. Another
difference between this project and real life blockchains is that each node in a real blockchain network has its own
copy of the blockchain and broadcasts it to other nodes, who then accept or reject it being the longest and therefore
correct blockchain. In this project, the only purpose of the nodes is to demonstrate proof of work, so the blockchain
is represented as a single object. Finally, the first coins in a real blockchain would be the ones from the genesis 
block being mined and wallets wouldn't start out with currency already in them. This project is more concerned with
how blockchain's operate ordinarily than when they are first starting out.

The program will run all the nodes on a loop to see which node finds the nonce first and will report to the user which
node received the reward. Each node will include it's address in the coinbase transaction, which is the first transaction
in the block header that gives each node a unique input and is how the nodes are rewarded their coins. Some blockchains 
have a maximum supply at which point the rewards will be supplied by transaction costs. For this project, there 
won't be a maximum supply and nodes will always be rewarded with newly minted currency. After each block, the 
program will display an updated quantity of currency in circulation, the difficulty level and the number of blocks.


Sources:
Bitcoin Whitepaper:

Bitcoin Sourcecode: