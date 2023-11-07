import React, {useState} from "react";


const MyCounter = (props) => {
    
    console.log(props);
    //let countState = 77
    const[countState, setCountState] = useState(77);

    function incCount(){
        //countState += 1;
        setCountState(countState + props.incBy);
    }

    return (
        <div>
            <div>{countState}</div>
            <button onClick={incCount}>+{props.incBy}</button>
        </div>
    )
}
export default MyCounter;