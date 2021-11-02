<nav class="navbar navbar-expand-lg navbar-light bg-light">
    <div class="container-fluid">
        <a class="navbar-brand" href="{{ route('product.index') }}">Ecommerce Website</a>
        <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
            <span class="navbar-toggler-icon"></span>
        </button>

        <div class="collapse navbar-collapse" id="navbarSupportedContent">
            <ul class="navbar-nav me-auto mb-2 mb-lg-0">
                <li class="nav-item">
                    <a class="nav-link active" aria-current="page" href="{{ route('product.shoppingCart') }}">Shopping Cart <span class="badge border" style="color: #2d3748">{{ \Illuminate\Support\Facades\Session::has('cart') ? \Illuminate\Support\Facades\Session::get('cart')->totalQty : '' }}</span>
                    </a>
                </li>
                <li class="nav-item dropdown">
                    <a class="nav-link dropdown-toggle" href="#" id="navbarDropdown" role="button" data-bs-toggle="dropdown" aria-expanded="false">
                            User Management
                    </a>
                    <ul class="dropdown-menu" aria-labelledby="navbarDropdown">
                        @if(\Illuminate\Support\Facades\Auth::check())

                            <li><a class="dropdown-item" href="{{ route('user.profile') }}">User Profile</a></li>
                            <li role="separator" class="dropdown-divider"></li>
                            <li><a class="dropdown-item" href="{{ route('user.logout') }}">Logout</a></li>
                        @else
                            <li><a class="dropdown-item" href="{{ route('user.signup') }}">Sign Up</a></li>
                            <li><a class="dropdown-item" href="{{ route('user.signin') }}">Sign In</a></li>
                        @endif
                    </ul>
                </li>
            </ul>
        </div>
    </div>
</nav>
