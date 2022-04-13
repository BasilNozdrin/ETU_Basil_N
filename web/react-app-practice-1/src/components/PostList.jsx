import React from 'react';
import PostItem from "./PostItem";

const PostList = ({posts, title, remove}) => {
    return (
        <div>
            <h1 style={{textAlign: 'center'}}>{title}</h1>
            {
                posts.length !== 0
                ?
                posts.map((post, index) => <PostItem remove={remove} number={index + 1} post={post} key={post.id}/>)
                :
                <h1 style={{textAlign:'center'}}>Posts not found!</h1>
            }
        </div>
    );
};

export default PostList;