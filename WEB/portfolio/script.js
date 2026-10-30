// Theme toggle + mobile menu
const toggle = document.getElementById('themeToggle');
const menuBtn = document.getElementById('menuBtn');
const navLinks = document.getElementById('navLinks');

// Load saved theme
if (localStorage.getItem('sh-theme') === 'dark') {
  document.body.classList.add('dark');
}

toggle.addEventListener('click', () => {
  document.body.classList.toggle('dark');
  localStorage.setItem(
    'sh-theme',
    document.body.classList.contains('dark') ? 'dark' : 'light'
  );
});

menuBtn.addEventListener('click', () => {
  navLinks.classList.toggle('open');
});

navLinks.querySelectorAll('a').forEach((a) =>
  a.addEventListener('click', () => navLinks.classList.remove('open'))
);
