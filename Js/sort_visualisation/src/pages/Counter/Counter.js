import React from "react";
import {Navbar} from "../../includes";

export class Counter extends React.Component {
    constructor(props) {
        super(props);

        // const {number} = props;
        this.state = {
            number: 0
        }
    }

    increment() {
        const {number} = this.state;
        this.setState({number: number + 1})
    }

    decrement() {
        const {number: c} = this.state;
        this.setState({number: c - 1})
    }

    reset() {
        this.setState({number: 0})
    }

    render() {
        return (
            <div style={{display: 'flex', flexDirection: 'column', margin: '0 auto'}}>
                {/*<Navbar/>*/}
                Pepega: {this.state.number}
                <br/>
                <button onClick={this.increment.bind(this)}>+</button>
                <button onClick={() => {this.decrement()}}>-</button>
                <br/>
                <button onClick={this.reset.bind(this)}>reset</button>
            </div>
        );
    }
}
