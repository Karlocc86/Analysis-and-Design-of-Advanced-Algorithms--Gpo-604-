function permute(nums: number[]): number[][] {

    let solution : number[][] = [];
    let path : number[] = [];

    const used: boolean[] = new Array(nums.length).fill(false);

    function backtrack() : void {

        if(path.length === nums.length){
            
            solution.push([...path]);
            return;
        }
        for( let i: number = 0 ; i < nums.length ; i++){
            
            if(used[i]) continue; // Prune
            used[i] = true;
            path.push(nums[i]); // Choose
            backtrack(); // Explore
            path.pop();  // Undo or POP
            used[i] = false;
        }



    }

    backtrack();

    return solution;
};


//Choices: all numbers inside an array
//Constrains: Cant reuse the same number more than once
// Base case: When the path lenght is equal to the size of the input array
//Backtrack step: 



/**  //Template

fuction backtrack(state){

    if state is a complete solution{

        recod a COPY of it
        return;
    }

    for each candidate choice at this state{

        if choice is not valid: continue /// The prune
        apply the choide to the state    /// CHOOSE
        backtrack(state)                 /// EXPLORE
        undo (POP) choice from state     /// UNCHOOSE or POP
    
    }


}



 */