// Gather demo feed: infinite scroll, refresh, mobile pull-to-refresh and post interactions.
// Replace fetchPosts() with your backend API when it is ready.



const feed = document.getElementById("feed");
const loader = document.getElementById("feedLoader");
const loaderText = document.getElementById("loaderText");
const endMessage = document.getElementById("endMessage");
const emptyMessage = document.getElementById("emptyMessage");
const retryButton = document.getElementById("retryButton");
const searchInput = document.getElementById("searchInput");

const PAGE_SIZE = 5;
let currentPage = 0;
let isLoading = false;
let hasMorePosts = true;
let searchTerm = "";
let touchStartY = 0;
let refreshing = false;
let toastTimer;

const samplePosts = [
  {id:1,author:"Maya Khan",initials:"MK",community:"Programming Club",age:"18 minutes ago",content:"Our team is preparing for the inter-college hackathon! 🚀 Anyone interested in collaborating?",likes:24,comments:6},
  {id:2,author:"Rafi Ahmed",initials:"RA",community:"Robotics Society",age:"1 hour ago",content:"A little progress from today's robotics workshop. We got our line-following robot working! 🤖",likes:18,comments:3},
  {id:3,author:"Nabila Sultana",initials:"NS",community:"Computer Science",age:"3 hours ago",content:"Starting a weekend study group for data structures and algorithms. Everyone is welcome! #StudyTogether",likes:31,comments:9},
  {id:4,author:"Tanvir Noor",initials:"TN",community:"Electronics Club",age:"5 hours ago",content:"Looking for teammates interested in building a small IoT project this semester. Share your ideas!",likes:12,comments:2},
  {id:5,author:"Farah Akter",initials:"FA",community:"Design Circle",age:"Yesterday",content:"Some tips from our UI design practice: start with the user, keep layouts clear, and iterate often.",likes:27,comments:4},
  {id:6,author:"Imran Hossain",initials:"IH",community:"Programming Club",age:"Yesterday",content:"Solved three graph problems today. Consistent practice really makes a difference!",likes:15,comments:5},
  {id:7,author:"Maya Khan",initials:"MK",community:"Programming Club",age:"2 days ago",content:"We are planning a beginner-friendly Git and GitHub session. What topics should we include?",likes:19,comments:7},
  {id:8,author:"Rafi Ahmed",initials:"RA",community:"Robotics Society",age:"2 days ago",content:"The robotics lab will be open this Friday for anyone who wants to experiment with Arduino.",likes:22,comments:3},
  {id:9,author:"Nabila Sultana",initials:"NS",community:"Computer Science",age:"3 days ago",content:"Reminder: our DSA study circle is meeting this weekend. Bring your questions and laptop!",likes:14,comments:2},
  {id:10,author:"Farah Akter",initials:"FA",community:"Design Circle",age:"3 days ago",content:"A good interface should feel simple because someone took the time to make it clear.",likes:33,comments:8},
  {id:11,author:"Imran Hossain",initials:"IH",community:"Programming Club",age:"4 days ago",content:"Anyone joining the next competitive programming practice? Let's solve problems together.",likes:11,comments:1},
  {id:12,author:"Tanvir Noor",initials:"TN",community:"Electronics Club",age:"4 days ago",content:"We tested our sensor module today. Next step: connecting everything to the dashboard.",likes:17,comments:4}
];

function toast(message) {
  const el = document.getElementById("toast");
  el.textContent = message;
  el.classList.add("show");
  clearTimeout(toastTimer);
  toastTimer = setTimeout(() => el.classList.remove("show"), 1900);
}

// Demo API simulation. Replace this with fetch('/api/posts?...') later.
async function fetchPosts(page, query = "") {
  await new Promise(resolve => setTimeout(resolve, 400));
  const matches = samplePosts.filter(p =>
    `${p.author} ${p.community} ${p.content}`.toLowerCase().includes(query)
  );
  const start = page * PAGE_SIZE;
  return {
    posts: matches.slice(start, start + PAGE_SIZE),
    hasMore: start + PAGE_SIZE < matches.length
  };
}

function makePost(post) {
  const article = document.createElement("article");
  article.className = "post";
  article.dataset.postId = post.id;

  const header = document.createElement("div");
  header.className = "post-head";
  const avatar = document.createElement("div");
  avatar.className = "avatar";
  avatar.textContent = post.initials || post.author[0].toUpperCase();

  const meta = document.createElement("div");
  meta.className = "post-meta";
  const name = document.createElement("div");
  name.className = "post-name";
  name.textContent = post.author;
  const time = document.createElement("div");
  time.className = "post-time";
  time.textContent = `${post.community} · ${post.age}`;
  meta.append(name, time);
  header.append(avatar, meta);

  const content = document.createElement("div");
  content.className = "post-text";
  content.textContent = post.content;

  const actions = document.createElement("div");
  actions.className = "post-actions";
  actions.innerHTML = `<button class="action like" type="button">♡ <strong>${post.likes} likes</strong></button>
    <button class="action comment-toggle" type="button">▢ ${post.comments} comments</button>
    <button class="action share" type="button">↗ Share</button>`;

  const comments = document.createElement("div");
  comments.className = "comments";
  const list = document.createElement("div");
  list.className = "comment-list";
  const row = document.createElement("div");
  row.className = "comment-row";
  const input = document.createElement("input");
  input.placeholder = "Write a comment...";
  const send = document.createElement("button");
  send.type = "button";
  send.className = "send-comment";
  send.textContent = "Send";
  row.append(input, send);
  comments.append(list, row);

  article.append(header, content, actions, comments);
  bindPost(article);
  return article;
}

function bindPost(post) {
  const like = post.querySelector(".like");
  like.addEventListener("click", () => {
    const liked = like.classList.toggle("liked");
    const count = like.querySelector("strong");
    const n = Number(count.textContent.match(/\d+/)?.[0] || 0);
    count.textContent = `${n + (liked ? 1 : -1)} likes`;
    like.firstChild.textContent = liked ? "♥ " : "♡ ";
  });

  post.querySelector(".comment-toggle").addEventListener("click", () => {
    post.querySelector(".comments").classList.toggle("open");
  });

  post.querySelector(".send-comment").addEventListener("click", () => {
    const input = post.querySelector(".comment-row input");
    const value = input.value.trim();
    if (!value) return;
    const line = document.createElement("div");
    line.textContent = `You: ${value}`;
    post.querySelector(".comment-list").append(line);
    input.value = "";
    post.querySelector(".comments").classList.add("open");
  });

  post.querySelector(".share").addEventListener("click", async () => {
    try {
      await navigator.clipboard.writeText(location.href);
      toast("Page link copied");
    } catch {
      toast("Clipboard is unavailable in this browser");
    }
  });
}

async function loadMorePosts() {
  if (isLoading || !hasMorePosts || searchTerm) return;
  isLoading = true;
  loader.hidden = false;
  loaderText.textContent = "Loading more posts...";
  retryButton.hidden = true;

  try {
    const data = await fetchPosts(currentPage);
    data.posts.forEach(post => feed.append(makePost(post)));
    currentPage++;
    hasMorePosts = data.hasMore;
    emptyMessage.hidden = feed.children.length > 0;
    loader.hidden = !hasMorePosts;
    endMessage.hidden = hasMorePosts || feed.children.length === 0;
  } catch (error) {
    console.error(error);
    loader.hidden = true;
    retryButton.hidden = false;
    toast("Couldn't load posts. Try again.");
  } finally {
    isLoading = false;
  }
}

async function refreshFeed() {
  if (refreshing) return;
  refreshing = true;
  currentPage = 0;
  hasMorePosts = true;
  feed.replaceChildren();
  endMessage.hidden = true;
  emptyMessage.hidden = true;
  retryButton.hidden = true;
  loader.hidden = false;
  loaderText.textContent = "Refreshing your feed...";

  try {
    if (searchTerm) {
      const data = await fetchPosts(0, searchTerm);
      data.posts.forEach(post => feed.append(makePost(post)));
      emptyMessage.hidden = data.posts.length > 0;
      loader.hidden = true;
    } else {
      await loadMorePosts();
    }
    toast("Feed refreshed");
  } finally {
    refreshing = false;
  }
}

async function searchPosts(query) {
  currentPage = 0;
  hasMorePosts = false;
  feed.replaceChildren();
  loader.hidden = true;
  endMessage.hidden = true;
  const data = await fetchPosts(0, query);
  data.posts.forEach(post => feed.append(makePost(post)));
  emptyMessage.hidden = data.posts.length > 0;
}

document.getElementById("refreshButton").addEventListener("click", async () => {
  await refreshFeed();
  window.scrollTo({top: 0, behavior: "smooth"});
});

searchInput.addEventListener("input", async event => {
  searchTerm = event.target.value.trim().toLowerCase();
  if (searchTerm) await searchPosts(searchTerm);
  else {
    currentPage = 0;
    hasMorePosts = true;
    feed.replaceChildren();
    await loadMorePosts();
  }
});

retryButton.addEventListener("click", loadMorePosts);

// Load the first batch and observe the loader near the bottom of the page.
loadMorePosts();
const observer = new IntersectionObserver(entries => {
  if (entries[0].isIntersecting) loadMorePosts();
}, {root: null, rootMargin: "300px", threshold: 0});
observer.observe(loader);

// Simple mobile pull-to-refresh when the user starts at the top.
document.addEventListener("touchstart", event => {
  if (window.scrollY === 0) touchStartY = event.touches[0].clientY;
}, {passive: true});

document.addEventListener("touchend", async event => {
  if (!touchStartY || window.scrollY !== 0) return;
  const distance = event.changedTouches[0].clientY - touchStartY;
  touchStartY = 0;
  if (distance > 110 && !refreshing) await refreshFeed();
}, {passive: true});

// Demo post composer: adds the new post at the top of the feed.
document.getElementById("postForm").addEventListener("submit", event => {
  event.preventDefault();
  const input = document.getElementById("postContent");
  const content = input.value.trim();
  if (!content) return toast("Write something before publishing");
  const post = {
    id: Date.now(), author: "Sajid Hossain", initials: "S",
    community: "Your community", age: "just now", content, likes: 0, comments: 0
  };
  feed.prepend(makePost(post));
  input.value = "";
  showNewPostMessage();
});

function showNewPostMessage() {
  toast("Your post has been published");
}



const nav_event = document.getElementById("nav_button_event");
nav_event.addEventListener("click", () => {
    window.location.href = "events.html";
});
