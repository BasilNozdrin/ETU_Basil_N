import {useState} from "react";
import "./styles/App.css";
import PostList from "./components/PostList";
import PostForm from "./components/PostForm";

function App() {
    const [posts, setPosts] = useState([
        {id: 1, title: 'Javascript', body: 'Discription'},
        {id: 2, title: 'Javascript 2', body: 'Discription'},
        {id: 3, title: 'жопа', body: 'Discription'}
    ])

    const createPost = (newPost) => {
        setPosts([...posts, newPost])
    }

    const removePost = (post) => {
        setPosts(posts.filter(p => p.id !== post.id))
    }

    return (
        <div className="App">
            <PostForm create={createPost}/>
            {posts.length !== 0
                ?
                <PostList remove={removePost} posts={posts} title="JS post list 1"/>
                :
                <h1 style={{textAlign:'center'}}>
                    Posts not found!
                </h1>
            }

        </div>
    );
}

export default App;
