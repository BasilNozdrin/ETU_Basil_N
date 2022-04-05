import React, {useState} from 'react';

const Counter = () => {
    const [count, setCount] = useState(0)

    /*  REACT HOOKS:
        useState    useEffect    useRef
        useMemo    useCallback    useContext    */

    function increment() {
        setCount(count+1)
    }

    function decrement() {
        setCount(count-1)
    }

    return (
        <div>
            <h1>{count}</h1>
            <button onClick={increment}>+</button>
            <button onClick={decrement}>-</button>
        </div>
    );
};

export default Counter;