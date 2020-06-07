import React from "react";
import './styles.scss';

import {Navbar} from '../../includes/Navbar/Navbar';

export class Homepage extends React.Component {

    render() {
        return (
            <div style={{display: 'flex', flexDirection: 'column', margin: '0 auto'}}>
                <Navbar/>
            </div>
        );
    }
}
